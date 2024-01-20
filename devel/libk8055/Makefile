PORTNAME=	libk8055
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.horizon9.org/~geroy/download/k8055/ \
		http://xz.cx/downloads/k8055/

MAINTAINER=	jake@xz.cx
COMMENT=	Velleman K8055 USB experimental board support and command line tool
WWW=		http://www.horizon9.org/~geroy/

LICENSE=	GPLv2+

USE_CSTD=	gnu89
USE_LDCONFIG=	yes

PLIST_FILES=	bin/k8055 \
		include/k8055.h \
		lib/libk8055.c \
		lib/libk8055.o \
		lib/libk8055.so \
		lib/libk8055.so.0.2 \
		share/man/man1/k8055.1.gz

post-patch:
	@${RM} ${WRKSRC}/libk8055.c.orig

.include <bsd.port.mk>
