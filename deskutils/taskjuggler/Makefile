# New ports collection makefile for: taskjuggler
# Date created:	23 February 2004
# Whom:	 	Dean Povey <povey@wedgetail.com>
#
# $FreeBSD$
#

PORTNAME=	taskjuggler
PORTVERSION=	2.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.taskjuggler.org/download/

MAINTAINER=	povey@wedgetail.com
COMMENT=	A project management tool for UNIX based operating systems

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/PostScript/Simple.pm:${PORTSDIR}/print/p5-PostScript-Simple \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		poster:${PORTSDIR}/print/poster \
		xsltproc:${PORTSDIR}/textproc/libxslt

BROKEN=		"Build fails"

OPTIONS=	KTJVIEW "Build KDE KTJView program (Requires KDE)" off

USE_BZIP2=	yes
USE_QT_VER=	3
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if defined(WITH_KTJVIEW)
LIB_DEPENDS+=	kwalletbackend:${PORTSDIR}/x11/kdelibs3
CONFIGURE_ARGS+=	--with-kde-support=yes
.include "files/ktjview-plist.mk"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|share/doc/packages/|share/doc/|g'

.include <bsd.port.post.mk>
