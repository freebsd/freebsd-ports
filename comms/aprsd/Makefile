# Created by: db
# $FreeBSD$

PORTNAME=	aprsd
PORTVERSION=	2.2.515
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.2.5-15
DISTNAME=	aprsd-2.2.5-15

MAINTAINER=	db@FreeBSD.org
COMMENT=	Server daemon providing Internet access to APRS packet data

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%CONFPATH%%|${PREFIX}/etc/aprsd/|' \
 	    -e 's|%%LOGPATH%%|/var/log/aprsd/|' \
		    ${WRKSRC}/src/aprsd.cpp
	@${REINPLACE_CMD} -e 's|%%LOGPATH%%|/var/log/aprsd/|' \
	    ${WRKSRC}/src/utils.cpp

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
	    ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/aprsd
	@${MKDIR} ${STAGEDIR}"/var/log/aprsd"
	@${SETENV} "PKG_PREFIX=${STAGEDIR}${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@cd ${WRKSRC}/admin
.for	f in INIT.TNC RESTORE.TNC aprsd.conf welcome.txt user.deny
	@${INSTALL_DATA} ${WRKSRC}/admin/$f ${STAGEDIR}${PREFIX}/etc/aprsd/$f.samp
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for	f in chkaprsd udp_example
	@${INSTALL_DATA} ${WRKSRC}/admin/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${INSTALL_SCRIPT}	${FILESDIR}/aprsd ${STAGEDIR}${LOCALBASE}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${CP} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
