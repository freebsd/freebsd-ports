# New ports collection makefile for:   scriba
# Date created:        07 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	scriba
PORTVERSION=	10b21
CATEGORIES=	lang
MASTER_SITES=	http://www.scriptbasic.com/download/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
# the filename of the current version has been re-styled as follows;
# however, as of November 2003, the patches do not apply cleanly, so
# this port needs further work.
#PORTVERSION=	1.0b30
#DISTNAME=	${PORTNAME}-v${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scripting implementation of the BASIC language

PRFXFILES=	variations/standard/basiccmd.c \
		variations/standalone/basicc.c \
		configurer.c scriba.c scriba.conf.unix.lsp \
		testconf.c

WRKSRC=		${WRKDIR}
USE_PERL5=	yes
CFLAGS+=	-fPIC

post-patch:
.for P in ${PRFXFILES}
	@(cd ${WRKSRC} && ${SED} -e 's,%%PREFIX%%,${PREFIX},g' $P > foo && \
		${MV} foo $P)
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/scriba
	${MKDIR} ${PREFIX}/include/scriba
	${MKDIR} ${PREFIX}/lib/scriba
	${CHMOD} 1666 ${PREFIX}/lib/scriba
	${INSTALL_PROGRAM} ${WRKSRC}/scriba ${PREFIX}/bin
.for M in cgi hash re
	${INSTALL_PROGRAM} ${WRKSRC}/$M.so ${PREFIX}/lib/scriba
.endfor
.for I in bdb cgi error gd hash heb md5 mysql re test time trial zlib ../heber
	${INSTALL_DATA} ${WRKSRC}/include/$I.bas ${PREFIX}/include/scriba
.endfor
	${INSTALL_DATA} ${WRKSRC}/basicc.a ${PREFIX}/lib/scriba
	${WRKSRC}/cftc ${WRKSRC}/scriba.conf.unix.lsp \
		${PREFIX}/etc/scriba/basic.conf

.include <bsd.port.mk>
