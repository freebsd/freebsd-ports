# Created by: ade@FreeBSD.org
# $FreeBSD$

PORTNAME=	autoconf
PORTVERSION=	2.69
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	autoconf-${PORTVERSION}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Automatically configure source code on many Un*x platforms

BUILD_DEPENDS=	gm4:devel/m4 \
		help2man:misc/help2man
RUN_DEPENDS=	gm4:devel/m4 \
		autoconf-wrapper:devel/autoconf-wrapper

BUILD_VERSION=	2.69
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USES=		gmake makeinfo perl5 tar:xz
INFO=		autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4 AWK=${AWK} \
		ac_cv_prog_TEST_EMACS=no
CONFIGURE_ARGS=	--program-suffix=-${BUILD_VERSION} --without-lispdir

GENERIC_TOOLS=	config.guess config.sub	elisp-comp install-sh mdate-sh missing
GENERIC_LINKS=	autoconf autoheader autom4te autoreconf autoscan autoupdate \
		ifnames

post-patch:
	@(cd ${WRKSRC}/man && \
		for file in *.[1x]; do \
			${REINPLACE_CMD} -E 's,([^-]auto)(conf|make|reconf|update|header|scan),\1\2-${BUILD_VERSION},g ; \
						s,(config\.guess|config\.sub|ifnames),\1-${BUILD_VERSION},g' $$file ; \
		done)
	@(cd ${WRKSRC}/doc && ${RM} -f *.info)
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@PACKAGE@$$|@PACKAGE@-@VERSION@|'

post-install:
.for FILE in ${GENERIC_TOOLS}
	@${INSTALL_SCRIPT} ${WRKSRC}/build-aux/${FILE} ${STAGEDIR}${PREFIX}/share/autoconf-${BUILD_VERSION}
.endfor

.include <bsd.port.mk>
