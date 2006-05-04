# New ports collection makefile for:   raknet
# Date created:        11 october 2005
# Whom:            dikiy

# $FreeBSD$

PORTNAME=	raknet
PORTVERSION=	2.0.13
CATEGORIES=	devel net
MASTER_SITES=	http://www.rakkarsoft.com/raknet/downloads/
DISTNAME=	RakNet

MAINTAINER=	dikiy@scn.ru
COMMENT=	Networking API that provides reliable UDP prmary for online games

USE_ZIP=	yes
WRKSRC=		${WRKDIR}

INSTALLS_SHLIB=		yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name CVS -delete
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" -e "s|-lpthread|${PTHREAD_LIBS}|" -e "s|-fPIC|-fPIC ${CFLAGS}|" ${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e "s|rm -f|#rm -f|g" -e "s|ln -s|${LN} -sf|" ${WRKSRC}/Makefile
	@for _F in `${FIND} ${WRKSRC} \
		-iregex '[^ ]*/makefile.*' -or \
		-iregex "[^ ]*/*.cpp" -or \
		-iregex "[^ ]*/*.h"`; do \
			${AWK} 'gsub( /\r/, "" )' $${_F} > $${_F}.awk.tmp; \
			${MV} $${_F}.awk.tmp $${_F}; \
	done
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e "s|stdint.h|inttypes.h|" ${WRKSRC}/Include/BitStream.h
	@${RM} ${WRKSRC}/Include/BitStream.h.bak
.endif
	@${MKDIR} ${WRKSRC}/Lib/linux
	@${LN} -s ${WRKSRC}/Lib ${WRKSRC}/lib

post-install:
	${LN} -sf ${PREFIX}/lib/libraknet.so.2.0.13 ${PREFIX}/lib/libraknet.so.0
	${LN} -sf ${PREFIX}/lib/librakvoice.so.2.0.13 ${PREFIX}/lib/librakvoice.so.0
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/DOxygen
	@cd ${WRKDIR}/Help && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKDIR}/Help && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
