PORTNAME=	ods2
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	filesystems sysutils
MASTER_SITES=	LOCAL/fuz
DISTNAME=	ods2

MAINTAINER=	pzn.unixbsd@gmail.com
COMMENT=	Utility for manipulating ODS-2 filesystems
WWW=		https://www.goatley.com/hunter/

LICENSE=	ODS2
LICENSE_NAME=	ODS2
LICENSE_TEXT=	ODS2 is distributed freely for all members of the \
		VMS community to use. However all derived works \
		must maintain comments in their source to acknowledge \
		the contibution of the original author.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.unix
MAKE_ARGS=	CCFLAGS="${CFLAGS}"

PLIST_FILES=	sbin/ods2
PORTDOCS=	aareadme.too aareadme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ods2 ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
