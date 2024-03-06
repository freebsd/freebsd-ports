PORTNAME=	gnucflow
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU/cflow/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to chart control flow within the C program
WWW=		https://www.gnu.org/software/cflow/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	bsdcflow cflow

USES=		cpe gmake tar:bzip2
CPE_VENDOR=	gnu
CPE_PRODUCT=	cflow
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
TEST_TARGET=	check

INFO=		cflow

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix="${LOCALBASE}"
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
