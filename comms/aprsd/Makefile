# Created by: db
# $FreeBSD$

PORTNAME=	aprsd
PORTVERSION=	2.2.515
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.2.5-15
DISTNAME=	aprsd-2.2.5-15

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Server daemon providing Internet access to APRS packet data

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message pkg-deinstall
USE_RC_SUBR=	aprsd

USERS=	aprsd tnc
GROUPS=	aprsd dialer tnc
APRSD_RC_USER=	aprsd
APRSD_RC_GROUP=	aprsd

RC_SUB_LIST=	LOCALBASE=${LOCALBASE} APRSD_RC_USER=${APRSD_RC_USER} \
		APRSD_RC_GROUP=${APRSD_RC_GROUP}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|%%CONFPATH%%|${PREFIX}/etc/aprsd/|' \
	    -e 's|%%LOGPATH%%|/var/log/aprsd/|' \
		    ${WRKSRC}/src/aprsd.cpp
	${REINPLACE_CMD} -e 's|%%LOGPATH%%|/var/log/aprsd/|' \
	    ${WRKSRC}/src/utils.cpp

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/aprsd
	${MKDIR} ${STAGEDIR}"/var/log/aprsd"

post-install:
	@cd ${WRKSRC}/admin
.for	f in INIT.TNC RESTORE.TNC aprsd.conf welcome.txt user.deny
	${INSTALL_DATA} ${WRKSRC}/admin/$f ${STAGEDIR}${PREFIX}/etc/aprsd/$f.samp
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for	f in chkaprsd udp_example
	${INSTALL_DATA} ${WRKSRC}/admin/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
