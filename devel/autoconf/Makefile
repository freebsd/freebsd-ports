PORTNAME=	autoconf
DISTVERSION=	2.72
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Generate configure scripts and related files
WWW=		https://www.gnu.org/software/autoconf/

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

USES=		perl5 tar:xz

VERSION=	${DISTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=${VERSION} \
		--without-lispdir
CONFIGURE_ENV=	AWK=${AWK} \
		EMACS=no \
		M4=${LOCALBASE}/bin/gm4

DATADIR=	${PREFIX}/share/autoconf${VERSION}
NO_ARCH=	yes

PLIST_SUB=	VERSION=${VERSION}

OPTIONS_DEFINE=	INFO
OPTIONS_DEFAULT=INFO

INFO_USES=	makeinfo
INFO_INFO=	autoconf${VERSION}

post-patch:
	@${REINPLACE_CMD} '/^pkgdatadir =/s/@PACKAGE@/&@VERSION@/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E \
		-e 's/[^-/]auto(conf|header|reconf|scan|update)/&${VERSION}/g' \
		-e 's/ifnames/&${VERSION}/g' \
		-e '/config\.(guess|sub)/d' \
		${WRKSRC}/man/*.1

post-patch-INFO-on:
	@${REINPLACE_CMD} -E 's/autoconf\.(info|texi)/autoconf${VERSION}.\1/g' \
		${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/doc/autoconf.texi ${WRKSRC}/doc/autoconf${VERSION}.texi
	@${REINPLACE_CMD} \
		-e 's/autoconf\.info/autoconf${VERSION}.info/' \
		-e '/^@direntry/,/^@end/ { \
			s/^\*[^-:]*/&${VERSION}/ ; \
			s/(autoconf)/(autoconf${VERSION})/ ; \
			s/ \{2,9\}/ / ; }' \
		${WRKSRC}/doc/autoconf${VERSION}.texi
# Restore timestamp in .info file.
	@${TOUCH} -r ${WRKSRC}/doc/autoconf${VERSION}.texi.bak \
		${WRKSRC}/doc/autoconf${VERSION}.texi

post-patch-INFO-off:
	@${REINPLACE_CMD} '/^INFO_DEPS =/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
