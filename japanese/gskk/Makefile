# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gskk
PORTVERSION=	20041208
CATEGORIES=	japanese
MASTER_SITES=	http://www.ohnolab.org/~kimoto/
EXTRACT_SUFX=	.t.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SKK's dictionary for Canna

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:japanese/canna-server
BUILD_DEPENDS=	mkbindic:japanese/canna-server

NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> ${PORTNAME}.t

PLIST_FILES=	share/canna/dic/canna/dics.dir.${PORTNAME} \
		share/canna/dic/canna/${PORTNAME}.cbd \
		share/canna/dic/canna/${PORTNAME}.cld
PORTDOCS=	README.FreeBSD

SUB_FILES=	README.FreeBSD pkg-message
SUB_LIST+=	DICDIR=${DICDIR} PORTNAME=${PORTNAME}

DICS=		${PORTNAME}.cbd ${PORTNAME}.cld
DICSFILE=	dics.dir.${PORTNAME}
DICDIR=		${PREFIX}/share/canna/dic/canna

INSTALL_DIC=	${INSTALL} ${COPY} -m 664

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && mkbindic ${PORTNAME}.t

do-install:
	@${MKDIR} ${STAGEDIR}${DICDIR}
	(cd ${WRKSRC} && ${INSTALL_DIC} ${DICS} ${STAGEDIR}${DICDIR})
	${INSTALL_DIC} ${FILESDIR}/${DICSFILE} ${STAGEDIR}${DICDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
