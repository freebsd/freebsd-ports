# New ports collection makefile for:	phpeclipse
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse
PORTVERSION=	1.1.8
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}.bin.dist

MAINTAINER=	lon_kamikaze@gmx.de
COMMENT=	PHP Eclipse adds PHP support to the Eclipse IDE Framework

PLIST_SUB=	VER=${PORTVERSION}

PLUGIN_PATHS=	features plugins

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	${PREFIX}/eclipse

do-install:
.for _path in ${PLUGIN_PATHS}
	@${MKDIR} ${ECLIPSE}/${_path}
	@${CP} -r ${WRKSRC}/${_path}/* ${ECLIPSE}/${_path}/
.endfor

plist: patch
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
.for _path in ${PLUGIN_PATHS}
	@${FIND} ${WRKSRC}/${_path}/ -type f \
		| ${SED} "s|${WRKSRC}|eclipse|1" \
		| ${SED} "s|${PORTVERSION}|%%VER%%|g" \
		>> ${PLIST}
	@${FIND} -d ${WRKSRC}/${_path}/ -mindepth 1 -type d \
		| ${SED} "s|${WRKSRC}|@dirrm eclipse|1" \
		| ${SED} "s|${PORTVERSION}|%%VER%%|g" \
		>> ${PLIST}
	@${ECHO} "@dirrmtry eclipse/${_path}" >> ${PLIST}
.endfor
	@${ECHO} "@dirrmtry eclipse" >> ${PLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
