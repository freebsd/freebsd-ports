# New ports collection makefile for:	REXX/imc
# Date created:				Septermber 21 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rexx-imc
PORTVERSION=	1.76
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://users.comlab.ox.ac.uk/ian.collier/distribution/ \
		ftp://ftp.sai.msu.su/pub/unix/rexx/ \
		ftp://crydee.sai.msu.ru/zeus/unix/rexx/

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	A procedural programming language designed by IBM's UK Laboratories

CONFLICTS=	rexx-regina-*

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Make
CONFIGURE_ENV=		CFLAGS="${CFLAGS}" \
			PREFIX="${PREFIX}"
CONFIGURE_ARGS=		o all
USE_REINPLACE=		yes

# configures and builds in one step
NO_BUILD=		yes

INSTALLS_SHLIB=		yes

MAN1=		rexx.1 rxstack.1 rxque.1

DOCFILES=	rexx.info rexx.ref rexx.summary rexx.tech
RMEFILES=	README README.Y2K README.bugreport README.docs \
		README.files README.make README.news README.platforms

post-patch:
# CFLAGS safeness for ARCHs other than i386
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Make
# CC safeness
	@${REINPLACE_CMD} -E -e 's|^CC=.+$$|CC=${CC}|' ${WRKSRC}/Make

do-install:
# install interpreter and daemon helpers
.for prog in rexx rxque rxstack
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
# install shared libraries, include file, and rxlib
# DO NOT delete rxlib or you will lose ability to call mathlib!!
.for lib in librexx.so.2 rxmathfn.rxfn
	@${INSTALL_PROGRAM} ${WRKSRC}/${lib} ${PREFIX}/lib
.endfor
	@${LN} -sf ${PREFIX}/lib/librexx.so.2 ${PREFIX}/lib/librexx.so
	@${INSTALL_DATA} ${WRKSRC}/rexxsaa.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/rxmathfn.rxlib ${PREFIX}/lib
# install man pages
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${man} ${PREFIX}/man/man1
.endfor
# install documenation and examples
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCFILES} ${RMEFILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${MKDIR} ${PREFIX}/share/examples/rexx-imc
.for ex in box rexxcps.rexx rexxtest.rexx rxmathfn.rexx shell.rexx
	@${INSTALL_SCRIPT} ${WRKSRC}/${ex} ${PREFIX}/share/examples/rexx-imc
.endfor
.endif

.include <bsd.port.mk>
