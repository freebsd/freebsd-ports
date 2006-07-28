# New ports collection makefile for:	quake2-ctf
# Date created:				26 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ctf
PORTVERSION=	1.50
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|:data,src|}
MASTER_SITE_SUBDIR=	quake2/ctf/:data \
			quake2/ctf/source/:src
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	${CTF_DATA}:data \
		${CTF_SRC}:src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Quake II CTF (Capture The Flag) modification

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${LATEST_LINK}

CTF_DATA=	q2ctf${PORTVERSION:S/.//}.zip
CTF_SRC=	q2ctf-1.02-source.shar.Z

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		uncompress -c ${DISTDIR}/${CTF_SRC} | ${TAIL} +394 | ${SH}
	@${UNZIP_CMD} -aq -d ${WRKDIR}/ctf \
		${DISTDIR}/${CTF_DATA} -x *.dll *.ico

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
	${MKDIR} ${Q2DIR}/ctf
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${Q2DIR}/ctf
.for f in *.cfg *.pak
	${INSTALL_DATA} ${WRKSRC}/ctf/${f} ${Q2DIR}/ctf
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ctf/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
