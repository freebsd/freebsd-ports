PORTNAME=	yagiuda
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.g8wrb.org/yagi/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Used to calculate yagi-uda antenna patterns useful to ham radio

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	4ti2 # bin/output

OPTIONS_DEFINE=	DOCS

do-install:
.for f in first optimise yagi dipole input output
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
.for f in first optimise yagi input output
	${INSTALL_MAN} ${WRKSRC}/man/man5/${f}.5 ${STAGEDIR}${PREFIX}/man/man5
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in dipole.1.html input.1.html pattern.jpg\
	first.1.html optimise.1.html yagi.1.html\
	index.html output.1.html yagi.jpg
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
