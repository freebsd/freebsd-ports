PORTNAME=	bindfs
DISTVERSION=	1.18.1
CATEGORIES=	filesystems
MASTER_SITES=	https://bindfs.org/downloads/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	doralitze@chaotikum.org
COMMENT=	FUSE based bindfs implementation way more powerful than nullfs
WWW=		https://bindfs.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse:3 localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fuse3
CONFIGURE_ENV+=	fuse3_LIBS="-L${LOCALBASE}/lib -lfuse3"

PLIST_FILES=	bin/bindfs \
		share/man/man1/bindfs.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|-lthr|g' \
	    ${PATCH_WRKSRC}/configure

.include <bsd.port.mk>
