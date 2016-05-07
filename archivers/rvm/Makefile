# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rvm
PORTVERSION=	1.11
CATEGORIES=	archivers
MASTER_SITES=	SF
PKGNAMESUFFIX=	an
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Archive manager that uses rsync to manage backups

LICENSE=	GPLv2

BUILD_DEPENDS=	rsync:net/rsync
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lang gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/rvm.conf \
		--enable-assume-stl-memory-exception
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/rvm man/man1/rvm.1.gz

.include <bsd.port.mk>
