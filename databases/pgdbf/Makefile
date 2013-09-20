# Created by: kirk@daycos.com
# $FreeBSD$

PORTNAME=	pgdbf
PORTVERSION=	0.6.2
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	kirk@strauser.com
COMMENT=	Convert XBase / FoxPro tables to PostgreSQL

LICENSE=	GPLv3

USE_XZ=		yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		pgdbf.1

PLIST_FILES=	bin/pgdbf \
		%%DOCSDIR%%/README
PLIST_DIRS=	%%DOCSDIR%%

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
