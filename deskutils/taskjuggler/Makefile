# New ports collection makefile for: taskjuggler
# Date created:	23 February 2004
# Whom:	 	Dean Povey <povey@wedgetail.com>
#
# $FreeBSD$
#

PORTNAME=	taskjuggler
PORTVERSION=	2.2.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.taskjuggler.org/download/

MAINTAINER=	ports@freebsd.org
COMMENT=	A project management tool for UNIX based operating systems

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/PostScript/Simple.pm:${PORTSDIR}/print/p5-PostScript-Simple \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		poster:${PORTSDIR}/print/poster
RUN_DEPENDS+=	${BUILD_DEPENDS}

OPTIONS=	DOCS "Build documentation" on \
		KDE "Build KDE frontend" on

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
USE_PERL5_RUN=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DOCS)
# do nada
.else
NOPORTDOCS=	true
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
.else
CONFIGURE_ARGS+=--disable-docs
.endif

.if !defined(WITHOUT_KDE)
LIB_DEPENDS+=	kimproxy:${PORTSDIR}/x11/kdelibs3
PLIST_SUB+=	WITH_KDE=""
.else
CONFIGURE_ARGS+=--with-kde-support=no
PLIST_SUB+=	WITH_KDE="@comment "
.endif

.if ${PERL_LEVEL} < 500600
BROKEN=		Perl > 5.6 is required.
.endif

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/share/doc/packages/taskjuggler|${DOCSDIR}|g' \
		-e 's|$$(prefix)/share/doc/packages/taskjuggler|${DOCSDIR}|g'
	@${SETENV} TZ=UTC ${TOUCH} -t 200512041507.49 ${WRKSRC}/Makefile.am.in
	@${SETENV} TZ=UTC ${TOUCH} -t 200512041507.52 ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
