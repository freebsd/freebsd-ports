PORTNAME=	autoconf
PORTVERSION=	2.13
CATEGORIES=	devel
MASTER_SITES=	LOCAL/ade/gnu
PKGNAMESUFFIX=	${VERSION}
DISTNAME=	autoconf-000227 # 2000-02-27 snapshot post 2.13

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Generate configure scripts and related files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4
RUN_DEPENDS=	autoconf-switch>=0:devel/autoconf-switch \
		gm4:devel/m4

VERSION=	2.13
USES=		desthack perl5 tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=${VERSION}
CONFIGURE_ENV=	AWK=${AWK} \
		M4=${LOCALBASE}/bin/gm4

STRIP=
DATADIR=	${PREFIX}/share/autoconf${VERSION}
NO_ARCH=	yes
PORTSCOUT=	ignore:1

WRKSRC=		${WRKDIR}/autoconf

PLIST_SUB=	VERSION=${VERSION}

OPTIONS_DEFINE=	INFO
OPTIONS_DEFAULT=INFO

INFO_USES=	makeinfo
INFO_INFO=	autoconf${VERSION}

post-patch:
	@${REINPLACE_CMD} '/^acdatadir =/s/autoconf/&${VERSION}/' \
		${WRKSRC}/Makefile.in
	@${RM} ${WRKSRC}/standards.texi

post-patch-INFO-on:
	@${REINPLACE_CMD} -E 's/autoconf\.(info|texi)/autoconf${VERSION}.\1/g' \
		${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/autoconf.texi ${WRKSRC}/autoconf${VERSION}.texi
	@${REINPLACE_CMD} \
		-e 's/autoconf\.info/autoconf${VERSION}.info/' \
		-e '/^@direntry/,/^@end/ { \
			s/^\*[^-:]*/&${VERSION}/ ; \
			s/(autoconf)/(autoconf${VERSION})/ ; \
			s/ \{2,9\}/ / ; }' \
		${WRKSRC}/autoconf${VERSION}.texi

post-patch-INFO-off:
	@${REINPLACE_CMD} \
		-e '/^all:/s/ info//' \
		-e '/^install:/s/ install-info//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
