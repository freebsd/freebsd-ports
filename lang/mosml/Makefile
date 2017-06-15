# Created by: Chuck Robey <chuckr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mosml
PORTVERSION=	2.10.1
DISTVERSIONPREFIX=	ver-
CATEGORIES=	lang

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Lightweight implementation of Standard ML

LIB_DEPENDS=	libgmp.so:math/gmp \
		libgdbm.so:databases/gdbm

GH_ACCOUNT=	kfl
USE_GITHUB=	yes

BROKEN_powerpc64=	Does not build

RESTRICTED=	Restrictions on for-profit distribution

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

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's/make /$$(MAKE) /' ${WRKSRC}/doc/Makefile \
		${WRKSRC}/doc/helpsigs/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/../copyrght/copyrght.att \
		${WRKSRC}/../copyrght/copyrght.cl \
		${WRKSRC}/../copyrght/gpl2 \
		${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . "${STAGEDIR}${EXAMPLESDIR}" \
		'-not ( -name *\.orig -o -name *\.bak -o -name *\.w32 )'
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/mosml/header
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mosml/lib*.so

.include <bsd.port.post.mk>
