# New ports collection makefile for:	festogi-spanish
# Date created:        			2000-06-19
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:59 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festogi-spanish
PORTVERSION=	2.0.1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	OGIspanish-${PORTVERSION}
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Mexican Spanish support for Festival

RUN_DEPENDS=	\
${PREFIX}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI

.if !defined(NOPORTDOCS)
PORTDOCS=	README-OGIspanish license_ogi_tts.txt
.endif
.for ii in duration intonation lexicon lts phones phrasing syl token
PLIST_FILES+=	share/festival/lib/ogi_spanish/ogi_span_mx_${ii}.scm
.endfor
PLIST_DIRS=	share/festival/lib/ogi_spanish

RESTRICTED=	no-commercial-use

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

pre-install:
	(${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf)

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}
	${MKDIR} ${DOCSDIR}
.if !defined(NOPORTDOCS)
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
