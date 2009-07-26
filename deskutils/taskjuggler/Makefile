# New ports collection makefile for: taskjuggler
# Date created:	23 February 2004
# Whom:	 	Dean Povey <povey@wedgetail.com>
#
# $FreeBSD$
#

PORTNAME=	taskjuggler
PORTVERSION=	2.4.3
CATEGORIES=	deskutils
MASTER_SITES=	http://www.taskjuggler.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A project management tool for UNIX based operating systems

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/PostScript/Simple.pm:${PORTSDIR}/print/p5-PostScript-Simple \
		poster:${PORTSDIR}/print/poster \
		bash:${PORTSDIR}/shells/bash \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS=	DOCS "Build documentation" on \
		KDE "Build KDE frontend" on

USE_BZIP2=	yes
USE_QT_VER=	3
USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_CFLAGS}"
CONFIGURE_ARGS=	--with-docdir=${EXAMPLESDIR}/
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DOCS)
NOPORTDOCS=	true
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
.else
CONFIGURE_ARGS+=--disable-docs
.endif

.if !defined(WITHOUT_KDE)
LIB_DEPENDS+=	kimproxy:${PORTSDIR}/x11/kdelibs3 \
		kcal.2:${PORTSDIR}/deskutils/kdepim3
PLIST_SUB+=	KDE=""
.else
CONFIGURE_ARGS+=--with-kde-support=no
PLIST_SUB+=	KDE="@comment "
.endif

.if defined(SESSION_MANAGER)
BROKEN=		please unset SESSION_MANAGER
.endif

post-patch:
	@cd ${WRKSRC}/admin && ${REINPLACE_CMD} -e \
		's|="autoconf"|="${AUTOCONF:T}"|g ; \
		 s|="autoheader"|="${AUTOHEADER:T}"|g ; \
		 s|="autom4te"|="${AUTOM4TE:T}"|g ; \
		 s|="automake"|="${AUTOMAKE:T}"|g ; \
		 s|="aclocal"|="${ACLOCAL:T}"|g' detect-autoconf.sh
	@${REINPLACE_CMD} -e 's| /bin/bash| ${LOCALBASE}/bin/bash|g ; \
		 s|^exit $$errors|exit 0|g' ${WRKSRC}/TestSuite/runtests
	@${REINPLACE_CMD} -e 's|exit 1|${ECHO_CMD} "*** Error detected - continue anyway ***"|' \
		${WRKSRC}/TestSuite/Misc/export/runtest
	@${FIND} ${WRKSRC}/TestSuite -name testdir | ${XARGS} \
			${REINPLACE_CMD} -e 's|exit $$errors|exit 0|'

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC}/admin && ${RM} -f libtool.m4.in && ${CP} -f ${LIBTOOL_M4}  libtool.m4.in
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

post-build:
	@${RMDIR} -p ~/.kde/share/config ~/.qt 2>/dev/null || ${TRUE}

post-install:
	@${RMDIR} -p ${EXAMPLESDIR} 2>/dev/null || ${TRUE}

regression-test:
	@(cd ${BUILD_WRKSRC}/TestSuite;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

.include <bsd.port.post.mk>
