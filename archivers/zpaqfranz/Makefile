PORTNAME=	zpaqfranz
DISTVERSION=	55.12
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.francocorbelli.it/zpaqfranz/freebsd/

MAINTAINER=	franco@francocorbelli.com
COMMENT=	Swiss army knife for the serious backup manager

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=		DIRCOMMAND
DIRCOMMAND_DESC=	Add a symlink to call the dir subcommand directly

PLIST_FILES=	bin/zpaqfranz

DIRCOMMAND_PLIST_FILES=		bin/dir
DIRCOMMAND_CONFLICTS_INSTALL=	gnuls

post-install-DIRCOMMAND-off:
		${RM} ${STAGEDIR}${LOCALBASE}/bin/dir

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64"
CFLAGS+=	-DNOJIT
.endif

.include <bsd.port.post.mk>
