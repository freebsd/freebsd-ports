PORTNAME=	libmng
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION} \
		http://www.libmng.com/download/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multiple-image Network Graphics (MNG) reference library
WWW=		https://sourceforge.net/projects/libmng/

LIB_DEPENDS=	liblcms2.so:graphics/lcms2

MAKEFILE=	${FILESDIR}/Makefile.bsd

USES=		jpeg uidfix tar:xz
USE_LDCONFIG=	yes

MAKE_ARGS+=	WITH_MNG_OPTIMIZE=true

post-install:
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} libmng.3 ${STAGEDIR}${PREFIX}/share/man/man3 \
		&& ${INSTALL_MAN} mng.5 jng.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
