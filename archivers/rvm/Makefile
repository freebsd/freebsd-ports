# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rvm
PORTVERSION=	1.07
CATEGORIES=	archivers
MASTER_SITES=	SF
PKGNAMESUFFIX=	an
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archive manager that uses rsync to manage backups

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/rvm.conf \
		--enable-assume-stl-memory-exception
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/rvm man/man1/rvm.1.gz

.include <bsd.port.mk>
