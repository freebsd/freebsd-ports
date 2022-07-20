PORTNAME=	autoconf
PORTVERSION=	2.69
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	${VERSION}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Generate configure scripts and related files

LICENSE=	EXCEPTION GFDL GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_NAME_EXCEPTION=	AUTOCONF CONFIGURE SCRIPT EXCEPTION
LICENSE_FILE_EXCEPTION=	${WRKSRC}/COPYING.EXCEPTION
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl.texi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYINGv3
LICENSE_PERMS_EXCEPTION=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	gm4:devel/m4
RUN_DEPENDS=	autoconf-switch>=0:devel/autoconf-switch \
		gm4:devel/m4

VERSION=	2.69
USES=		perl5 tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=${VERSION} \
		--without-lispdir
CONFIGURE_ENV=	AWK=${AWK} \
		EMACS=no \
		M4=${LOCALBASE}/bin/gm4

DATADIR=	${PREFIX}/share/autoconf${VERSION}
NO_ARCH=	yes
PORTSCOUT=	ignore:1

PLIST_SUB=	VERSION=${VERSION}

OPTIONS_DEFINE=	INFO
OPTIONS_DEFAULT=INFO

INFO_USES=	makeinfo
INFO_INFO=	autoconf${VERSION}

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		'/^pkgdatadir =/s/@PACKAGE@/&@VERSION@/' {} +
	@${REINPLACE_CMD} -E \
		-e 's,([^-/]auto)(conf|header|reconf|scan|update),\1\2${VERSION},g' \
		-e 's,(config\.guess|config\.sub|ifnames),\1${VERSION},g' \
		${WRKSRC}/man/*.1
# Save timestamps.
	@${LN} ${WRKSRC}/build-aux/config.guess \
		${WRKSRC}/build-aux/config.guess.orig
	@${LN} ${WRKSRC}/build-aux/config.sub \
		${WRKSRC}/build-aux/config.sub.orig

post-patch-INFO-on:
	@${REINPLACE_CMD} -E 's/autoconf\.(info|texi)/autoconf${VERSION}.\1/g' \
		${WRKSRC}/doc/Makefile.in
	@${CP} ${WRKSRC}/doc/autoconf.texi ${WRKSRC}/doc/autoconf${VERSION}.texi
	@${REINPLACE_CMD} \
		-e 's/autoconf\.info/autoconf${VERSION}.info/' \
		-e '/^@direntry/,/^@end/ { \
			s/^\*[^-:]*/&${VERSION}/ ; \
			s/(autoconf)/(autoconf${VERSION})/ ; \
			s/ \{2,9\}/ / ; }' \
		${WRKSRC}/doc/autoconf${VERSION}.texi
# Restore timestamp in .info file.
	@${TOUCH} -r ${WRKSRC}/doc/autoconf.texi.orig \
		${WRKSRC}/doc/autoconf${VERSION}.texi

post-patch-INFO-off:
	@${REINPLACE_CMD} '/^INFO_DEPS =/d' ${WRKSRC}/doc/Makefile.in

post-configure:
# Restore timestamps to prevent regeneration of man pages.
	@${TOUCH} -r ${WRKSRC}/build-aux/config.guess.orig \
		${WRKSRC}/build-aux/config.guess
	@${TOUCH} -r ${WRKSRC}/build-aux/config.sub.orig \
		${WRKSRC}/build-aux/config.sub

.include <bsd.port.mk>
