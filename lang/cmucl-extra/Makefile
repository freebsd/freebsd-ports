# Created by: Scott Flatman <sf@dsinw.com>

PORTNAME=	cmucl-extra
DISTVERSION=	21b
CATEGORIES=	lang lisp
MASTER_SITES=	https://common-lisp.net/project/cmucl/downloads/release/${DISTVERSION}/ \
		http://cmucl.org/downloads/release/${DISTVERSION}/ \
		https://pmsf.eu/pub/cmucl/release/${DISTVERSION}/ \
		http://www.rgrjr.com/cmucl/downloads/release/${DISTVERSION}/
DISTNAME=	cmucl-${DISTVERSION}-x86-FreeBSD.extra

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optional extras for the CMU implementation of Common Lisp

LICENSE=	PD

BROKEN=		lang/cmucl is broken since 12.1
DEPRECATED=	lang/cmucl is not supported upstream since 2017 and broken since FreeBSD 12.1
EXPIRATION_DATE=	2022-06-25

RUN_DEPENDS=	lisp:lang/cmucl

USES=		tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

do-install:
	cd ${WRKSRC}/lib/cmucl &&  ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR}/lib && ${COPYTREE_SHARE} locale ${STAGEDIR}${PREFIX}/share '-name *\.mo'
	${RM} `${FIND} ${STAGEDIR}${DATADIR} -name "*.mo"`
	${RMDIR} ${STAGEDIR}${DATADIR}/lib/contrib/unix

.include <bsd.port.mk>
