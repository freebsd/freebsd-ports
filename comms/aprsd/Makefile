PORTNAME=	aprsd
PORTVERSION=	2.2.515
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.2.5-15
DISTNAME=	aprsd-2.2.5-15

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Server daemon providing Internet access to APRS packet data
WWW=		https://sourceforge.net/projects/aprsd/

LICENSE=	GPLv2

USE_CXXSTD=	c++14
USE_RC_SUBR=	aprsd

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	APRSD_RC_USER=${APRSD_RC_USER} \
		APRSD_RC_GROUP=${APRSD_RC_GROUP}

USERS=	aprsd tnc
GROUPS=	aprsd dialer tnc
APRSD_RC_USER=	aprsd
APRSD_RC_GROUP=	aprsd

OPTIONS_DEFINE=	DOCS EXAMPLES

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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for	f in chkaprsd udp_example
	${INSTALL_DATA} ${WRKSRC}/admin/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
