# Created by: alepulver
# $FreeBSD$

PORTNAME=	alienarena
PORTVERSION=	2013.766
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linux.kiev.ua/pub/Linux/Gentoo/distfiles/ \
		http://ftp.jeuxlinux.fr/files/ \
		http://mirror.ipgn.com.au/games/alienarena/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
		http://offload2.icculus.org:9090/alienarena/Files/ \
		http://offload1.icculus.org:9090/alienarena/Files/ \
		http://icculus.org/alienarena/Files/ \
		http://red.planetarena.org/files/ \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}-7.66-linux20130827

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Alien Arena (data)

NO_BUILD=	yes
NO_PACKAGE=	Package will be 600MB, set FORCE_PACKAGE if you want it
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}-7.66

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-install:
	@${RM} -f ${PLIST}

.	for DIRE in arena botinfo data1
		@cd ${WRKSRC} && \
			${FIND} ${DIRE} -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
				${FIND} ${DIRE} -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
.	endfor

	@${ECHO_CMD} share/pixmaps/${PORTNAME}.png >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

.	if !defined(NOPORTDOCS)
		@cd ${WRKSRC}/docs && \
			${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%PORTDOCS%%%%DOCSDIR%%/|' >> ${PLIST} && \
				${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|%%PORTDOCS%%@dirrm %%DOCSDIR%%/|' >> ${PLIST}
		@${ECHO_CMD} "%%PORTDOCS%%@dirrmtry %%DOCSDIR%%" >> ${PLIST}
.	endif

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R arena botinfo data1 ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
