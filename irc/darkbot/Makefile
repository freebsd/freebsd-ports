# Created by: A. Gabriel <backslash@BSDCode.org>
# $FreeBSD$

PORTNAME=	darkbot
PORTVERSION=	6f6.r6
PORTEPOCH=	1
CATEGORIES=	irc
MASTER_SITES=	http://darkbot.sourceforge.net/archive/unix/ \
		http://www.BSDCode.org/port/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC talking bot with a very fast algorithm for its database

SUB_FILES=	pkg-message

MAN1=		darkbot.1
MANCOMPRESSED=	yes

PORTDOCS=	README
PLIST_FILES=	bin/darkbot %%ETCDIR%%/logs/.pkgcreate

.include <bsd.port.options.mk>

post-patch:
	${CP} ${WRKSRC}/configure ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${MAN1PREFIX}/man/man1/

post-install:
	${MKDIR} ${ETCDIR}/dat ${ETCDIR}/logs
	${TOUCH} ${ETCDIR}/logs/.pkgcreate
	cd ${WRKSRC}/dat; \
	for file in *; do \
	    ${INSTALL_DATA} $$file ${ETCDIR}/dat/$${file}.dist; \
	    ${CP} -np ${ETCDIR}/dat/$${file}.dist ${ETCDIR}/dat/$$file; \
	    ${ECHO_CMD} "@unexec cmp -s ${ETCDIR}/dat/$$file \
		${ETCDIR}/dat/$${file}.dist && \
		rm -f ${ETCDIR}/dat/$$file || true" >> ${TMPPLIST}; \
	    ${ECHO_CMD} "${ETCDIR_REL}/dat/$${file}.dist" >> ${TMPPLIST}; \
	    ${ECHO_CMD} "@exec cp -np %D/%F %B/$$file" >> ${TMPPLIST}; \
	done
	${ECHO_CMD} "@unexec rmdir ${ETCDIR}/logs 2>/dev/null || true" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec rmdir ${ETCDIR}/dat 2>/dev/null || true" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec rmdir ${ETCDIR} 2>/dev/null || true" >> ${TMPPLIST}
	${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/configure
	${ECHO_CMD} 'cd ${ETCDIR} && ${SH} config' >> ${WRKSRC}/configure
.for s in config configure AddServer Adduser
	${INSTALL_SCRIPT} ${WRKSRC}/$s ${ETCDIR}
	${ECHO_CMD} ${ETCDIR_REL}/$s >> ${TMPPLIST}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
