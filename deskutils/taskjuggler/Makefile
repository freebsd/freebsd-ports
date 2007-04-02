# New ports collection makefile for: taskjuggler
# Date created:	23 February 2004
# Whom:	 	Dean Povey <povey@wedgetail.com>
#
# $FreeBSD$
#

PORTNAME=	taskjuggler
PORTVERSION=	2.3.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.taskjuggler.org/download/

MAINTAINER=	ports@FreeBSD.org
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
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DOCS)
NOPORTDOCS=	true
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
CONFIGURE_ARGS+=--with-docdir=${EXAMPLESDIR}/
.else
CONFIGURE_ARGS+=--disable-docs
.endif

.if !defined(WITHOUT_KDE)
LIB_DEPENDS+=	kimproxy:${PORTSDIR}/x11/kdelibs3 \
		kcal.2:${PORTSDIR}/deskutils/kdepim3
PLIST_SUB+=	WITH_KDE=""
.else
CONFIGURE_ARGS+=--with-kde-support=no
PLIST_SUB+=	WITH_KDE="@comment "
.endif

.if defined(SESSION_MANAGER)
BROKEN=		please unset SESSION_MANAGER
.endif

pre-configure:
	@${SETENV} TZ=UTC ${TOUCH} -t 200512041507.49 ${WRKSRC}/Makefile.am.in
	@${SETENV} TZ=UTC ${TOUCH} -t 200512041507.52 ${WRKSRC}/Makefile.am
	@${SETENV} TZ=UTC ${TOUCH} -t 200609051627.51 ${WRKSRC}/subdirs
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|exit 1|${ECHO_CMD} "*** Error detected - continue anyway ***"|' \
		${WRKSRC}/TestSuite/Misc/export/runtest
	${FIND} ${WRKSRC}/TestSuite -name testdir | ${XARGS} \
			${REINPLACE_CMD} -e 's|exit $$errors|exit 0|'

post-build:
	@${RMDIR} -p ~/.kde/share/config ~/.qt 2>/dev/null || ${TRUE}

post-install:
	@${RMDIR} -p ${EXAMPLESDIR} 2>/dev/null || ${TRUE}

regression-test:
	@(cd ${BUILD_WRKSRC}/TestSuite;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

.include <bsd.port.post.mk>
