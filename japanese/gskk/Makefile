# New ports collection makefile for:	gskk
# Date created:		7 Mar 2005
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>

#
# $FreeBSD$
#

PORTNAME=	gskk
PORTVERSION=	20041208
CATEGORIES=	japanese
MASTER_SITES=	http://www.ohnolab.org/~kimoto/
DISTNAME=	${PORTNAME}-${PORTVERSION}.t
EXTRACT_SUFX=	.gz

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SKK's dictionary for Canna

RUN_DEPENDS=	${LOCALBASE}/sbin/cannaserver:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	mkbindic:${PORTSDIR}/japanese/Canna

NO_WRKSUBDIR=	yes

EXTRACT_AFTER_ARGS=	> ${PORTNAME}.t

PLIST_FILES=	share/canna/dic/canna/dics.dir.${PORTNAME} \
		share/canna/dic/canna/${PORTNAME}.cbd \
		share/canna/dic/canna/${PORTNAME}.cld

.if !defined(NOPORTDOCS)
PORTDOCS=	README.FreeBSD
.endif

SUB_FILES=	README.FreeBSD pkg-message
SUB_LIST+=	DICDIR=${DICDIR} PORTNAME=${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message

DICS=		${PORTNAME}.cbd ${PORTNAME}.cld
DICSFILE=	dics.dir.${PORTNAME}
DICDIR=		${PREFIX}/share/canna/dic/canna

INSTALL_DIC=	${INSTALL} ${COPY} -o bin -g bin -m 664

do-build:
	cd ${WRKDIR} && mkbindic ${PORTNAME}.t

do-install:
	cd ${WRKSRC} && ${INSTALL_DIC} ${DICS} ${DICDIR}
	${INSTALL_DIC} ${FILESDIR}/${DICSFILE} ${DICDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.FreeBSD ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
