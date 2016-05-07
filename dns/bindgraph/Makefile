# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bindgraph
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.linux.it/~md/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RRDtool frontend for BIND statistics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool	\
		p5-File-Tail>=0:devel/p5-File-Tail

NO_BUILD=	yes
USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	bindgraph.pl bindgraph.cgi

CGIDIR?=	${PREFIX}/www/cgi-bin
DATADIR?=	/var/db/bindgraph
BINDGRAPH_USER?=	${WWWOWN}
BINDGRAPH_GROUP?=	${WWWGRP}

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	BINDGRAPH_USER=${BINDGRAPH_USER} BINDGRAPH_GROUP=${BINDGRAPH_GROUP}
PLIST_SUB=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} \
		BINDGRAPH_USER="${BINDGRAPH_USER}" \
		BINDGRAPH_GROUP="${BINDGRAPH_GROUP}"

DOCS=		README ChangeLog
PORTDOCS=	${DOCS}

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DATADIR=/var/db/bindgraph	Where do you put RRD databases?"
	@${ECHO_MSG} "CGIDIR=${PREFIX}/www/cgi-bin	Where do you put cgi?"
	@${ECHO_MSG} "BINDGRAPH_USER=www		User to run bindgraph (Default: ${WWWOWN})"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/bindgraph.cgi

do-install:
	${MKDIR} ${STAGEDIR}${CGIDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bindgraph.pl ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/bindgraph.cgi ${STAGEDIR}${CGIDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}/; \
	done

.include <bsd.port.mk>
