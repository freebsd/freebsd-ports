# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	db41
PORTVERSION=	4.1.25
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/
PKGNAMESUFFIX?=
DISTNAME?=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://download.oracle.com/berkeley-db/patches/db/${PORTVERSION}/
PATCHFILES=	patch.${PORTVERSION}.2
PATCH_DIST_STRIP=	-d ${WRKDIR}/${DISTNAME}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 4.1

CONFLICTS?=	db41-nocrypto-4*

DEPRECATED=	Please use databases/db5 or db6 for new installs.

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=	--enable-compat185 --enable-dump185 \
		--enable-cxx --enable-dynamic \
		--includedir=${PREFIX}/include/db41
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install install_docs
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-mutex=x86/gcc-assembly
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
