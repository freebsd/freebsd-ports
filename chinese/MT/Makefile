# New ports collection makefile for:	MT
# Date created:		7 Oct 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sincia.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION=	2.64
CATEGORIES=	chinese
MASTER_SITES=	http://www.movabletype.org/downloads/
DISTNAME=	mt-zh-tw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based personal publishing system like weblogs

RUN_DEPENDS=	${LOCALBASE}/${CGIDIR}/mt.cgi:${PORTSDIR}/www/MT

NO_BUILD=	yes

DATADIR=	www/data/mt
CGIDIR=		www/cgi-bin/mt
PLIST_SUB+=	DATADIR=${DATADIR} CGIDIR=${CGIDIR}
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

do-install:
	${REINPLACE_CMD} -e 's/# PublishCharset Shift_JIS/PublishCharset UTF-8/g' \
		${PREFIX}/${CGIDIR}/mt.cfg
	${REINPLACE_CMD} -e 's,en-us,zh-tw,g' \
		${PREFIX}/${CGIDIR}/lib/MT/App/Trackback.pm \
		${PREFIX}/${CGIDIR}/lib/MT/App/CMS.pm \
		${PREFIX}/${CGIDIR}/lib/MT/default-templates.pl \
		${PREFIX}/${CGIDIR}/mt-load.cgi
	${RM} ${PREFIX}/${CGIDIR}/lib/MT/App/Trackback.pm.bak \
		${PREFIX}/${CGIDIR}/lib/MT/App/CMS.pm.bak \
		${PREFIX}/${CGIDIR}/lib/MT/default-templates.pl.bak \
		${PREFIX}/${CGIDIR}/mt-load.cgi.bak \
		${PREFIX}/${CGIDIR}/mt.cfg.bak
	@${CP} ${WRKDIR}/mt-zh-tw/zh_tw.pm ${PREFIX}/${CGIDIR}/extlib/MT/L10N/
	@${CP} -R ${WRKDIR}/mt-zh-tw/lang-zh-tw/ ${PREFIX}/${DATADIR}/images/lang-zh-tw/

.include <bsd.port.post.mk>
