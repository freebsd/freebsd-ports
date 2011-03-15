# Ports collection makefile for:  klone
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klone
PORTVERSION=	2.1.359
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/Klone/
DISTNAME=	Klone${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, Lisp-like interpreted language

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/Klone

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

do-configure:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:' \
		-e 's:%%CC%%:${CC}:' \
		-e 's:%%CFLAGS%%:${CFLAGS}:' \
		${FILESDIR}/freebsd > ${WRKSRC}/Configs/freebsd
	@${CP} -f ${WRKSRC}/Configs/freebsd ${WRKSRC}/Config.freebsd
	@${ECHO_CMD} "freebsd" > ${WRKSRC}/.dir
	@${RM} -f makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/klone ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/klone
	${INSTALL_DATA} ${WRKSRC}/kl/* ${PREFIX}/lib/klone
	@${MKDIR} ${PREFIX}/lib/klone/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/lib/klone/scripts
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
