# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$
#
# This is a set of Makefile macros that are common between devel/eric6 and
# localized language packages for devel/eric6:
# chinese/eric6, french/eric6, german/eric6, portuguese/eric6, russian/eric6
# devel/cs-eric6, devel/es-eric6, devel/it-eric6, devel/tr-eric6

PORTNAME=	eric6
PORTVERSION=	18.02
MASTER_SITES=	SF/eric-ide/${PORTNAME}/stable/${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Full featured Python and Ruby editor and IDE based on Qt

LICENSE=	GPLv3

DESCR=		${.CURDIR}/../../devel/eric6/pkg-descr
MAKE_ENV+=	"HOME=${WRKDIR}"

NO_BUILD=	yes
