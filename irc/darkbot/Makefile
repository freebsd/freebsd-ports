# Created by: A. Gabriel <backslash@BSDCode.org>
# $FreeBSD$

PORTNAME=	darkbot
PORTVERSION=	6f6.r6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	irc
MASTER_SITES=	http://darkbot.sourceforge.net/archive/unix/ \
		http://www.BSDCode.org/port/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC talking bot with a fast algorithm for its database

SUB_FILES=	pkg-message

PORTDOCS=	README
PLIST_FILES=	bin/darkbot %%ETCDIR%%/logs/.pkgcreate man/man1/darkbot.1.gz
NO_CDROM=	no commercial distribution

OPTIONS_DEFINE=	DOCS

pre-configure:
	${CP} ${WRKSRC}/configure ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${ETCDIR}/dat ${STAGEDIR}${ETCDIR}/logs
	${TOUCH} ${STAGEDIR}${ETCDIR}/logs/.pkgcreate
	cd ${WRKSRC}/dat; \
	for file in *; do \
	    ${INSTALL_DATA} $$file ${STAGEDIR}${ETCDIR}/dat/$${file}.dist; \
	    ${CP} -np ${ETCDIR}/dat/$${file}.dist ${STAGEDIR}${ETCDIR}/dat/$$file || ${TRUE} ; \
	    ${ECHO_CMD} "@unexec cmp -s ${ETCDIR}/dat/$$file \
		${ETCDIR}/dat/$${file}.dist && \
		rm -f ${ETCDIR}/dat/$$file || true" >> ${TMPPLIST}; \
	    ${ECHO_CMD} "${ETCDIR_REL}/dat/$${file}.dist" >> ${TMPPLIST}; \
	    ${ECHO_CMD} "@exec cp -np %D/%F %B/$$file || true" >> ${TMPPLIST}; \
	done
	${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/configure
	${ECHO_CMD} 'cd ${ETCDIR} && ${SH} config' >> ${WRKSRC}/configure
.for s in config configure AddServer Adduser
	${INSTALL_SCRIPT} ${WRKSRC}/$s ${STAGEDIR}${ETCDIR}
	${ECHO_CMD} ${ETCDIR_REL}/$s >> ${TMPPLIST}
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
