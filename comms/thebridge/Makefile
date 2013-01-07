# Created by: db
# $FreeBSD$
#

PORTNAME=	thebridge
PORTVERSION=	1.09
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Echolink conference bridge

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
PORTDOCS=	README
USE_RC_SUBR=	tbd
USE_AUTOTOOLS=	autoconf
CONFIGURE_ENV=	AUTOMAKE=/usr/bin/true
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},; \
		s,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/addons/usermgmt.cgi

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/addons/usermgmt.cgi ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addons/README ${DATADIR}

.include <bsd.port.mk>
