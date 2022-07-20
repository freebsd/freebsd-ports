PORTNAME=	mosml
PORTVERSION=	2.10.1
DISTVERSIONPREFIX=	ver-
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight implementation of Standard ML

# Converted from RESTRICTED
LICENSE=	mosml
LICENSE_NAME=	mosml
LICENSE_TEXT=	Restrictions on for-profit distribution
LICENSE_PERMS=	auto-accept

BROKEN_mips=		does not configure: this architecture seems to be neither big endian nor little endian
BROKEN_mips64=		does not configure: this architecture seems to be neither big endian nor little endian
BROKEN_powerpc64=	does not configure: this architecture seems to be neither big endian nor little endian

LIB_DEPENDS=	libgmp.so:math/gmp \
		libgdbm.so:databases/gdbm

GH_ACCOUNT=	kfl
USE_GITHUB=	yes

USES=		compiler:features gmake perl5
ALL_TARGET=	world
MAKE_ARGS=	ADDRUNLIBS= \
		CC="${CC}" \
		CPP="${CPP} -P -traditional -Dunix -Umsdos" \
		DOCSDIR="${DOCSDIR}" \
		DYNLD="${CC} -shared" \
		LD="${CC}" \
		LD_RUN_PATH="${PREFIX}/lib/mosml" \
		MOSMLHOME="${MOSMLHOME}" \
		STRIP="${STRIP_CMD}"
WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's/make /$$(MAKE) /' ${WRKSRC}/doc/Makefile \
		${WRKSRC}/doc/helpsigs/Makefile

post-install:
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/mosml/header
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mosml/lib*.so

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/../copyrght/copyrght.att \
		${WRKSRC}/../copyrght/copyrght.cl \
		${WRKSRC}/../copyrght/gpl2 \
		${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . "${STAGEDIR}${EXAMPLESDIR}" \
		'-not ( -name *\.orig -o -name *\.bak -o -name *\.w32 )'

.include <bsd.port.mk>
