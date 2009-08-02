# ex:ts=8
# New ports collection makefile for:	styx
# Date created:			Apr 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	styx
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.speculate.de/styx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scanner/parser generator

USE_AUTOTOOLS=	libtool:22
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
USE_LDCONFIG=	yes

post-patch:
.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e '/SUBDIRS/s|spexml||' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc \
		--exclude "*.in" --exclude "*Makefile*" -cf - . | \
			${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC} \
		--exclude "*.in" --exclude "*Makefile*" -cf - spe pat | \
			${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
