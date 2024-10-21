PORTNAME=	ufs_copy
PORTVERSION=	20060921
PORTREVISION=	2
CATEGORIES=	filesystems sysutils
MASTER_SITES=	https://people.freebsd.org/~simokawa/ufs/
DISTNAME=	ufs-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Fast copy utility for UFS filesystem
WWW=		https://people.freebsd.org/~simokawa/ufs/

LICENSE=	BSD4CLAUSE

USES=		uidfix
WRKSRC=		${WRKDIR}/ufs
MAKE_ARGS=	BINDIR=${PREFIX}/sbin

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	sbin/ufs_copy

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
