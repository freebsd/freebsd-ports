# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umem
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://labs.omniti.com/portableumem/releases/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the Solaris memory allocator

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/OPENSOLARIS.LICENSE

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check  # XXX: 1 of 4 tests fail

post-patch:
	@${REINPLACE_CMD} -e 's/ -ldl//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
