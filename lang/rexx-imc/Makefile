# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rexx-imc
PORTVERSION=	1.76
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.ox.ac.uk/people/ian.collier/distribution/ \
		ftp://ftp.sai.msu.su/pub/unix/rexx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Procedural programming language designed by IBM's UK Laboratories

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFLICTS=	rexx-regina-* oorexx-[0-9]*

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Make
CONFIGURE_ENV=		PREFIX="${PREFIX}"
CONFIGURE_ARGS=		o all

# configures and builds in one step
NO_BUILD=		yes

USE_LDCONFIG=		yes

MAN1=		rexx.1 rxstack.1 rxque.1

DOCFILES=	rexx.info rexx.ref rexx.summary rexx.tech
RMEFILES=	README README.Y2K README.bugreport README.docs \
		README.files README.make README.news README.platforms

.include <bsd.port.options.mk>

post-patch:
# CFLAGS safeness for ARCHs other than i386
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Make
# CC safeness
	@${REINPLACE_CMD} -E -e 's|^CC=.+$$|CC=${CC}|' ${WRKSRC}/Make

do-install:
# install interpreter and daemon helpers
.for prog in rexx rxque rxstack
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${prog} ${PREFIX}/bin)
.endfor
# install shared libraries, include file, and rxlib
	(cd ${WRKSRC} && ${INSTALL_DATA} rexxsaa.h ${PREFIX}/include)
# DO NOT delete rxlib or you will lose ability to call mathlib!!
.for lib in librexx.so.2 rxmathfn.rxfn rxmathfn.rxlib
	(cd ${WRKSRC} && ${INSTALL_DATA} ${lib} ${PREFIX}/lib)
.endfor
	@${LN} -sf librexx.so.2 ${PREFIX}/lib/librexx.so
# install man pages
.for man in ${MAN1}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${man} ${MANPREFIX}/man/man1)
.endfor
# install documenation and examples
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCFILES} ${RMEFILES}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${DOCSDIR})
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for ex in box rexxcps.rexx rexxtest.rexx rxmathfn.rexx shell.rexx
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${ex} ${EXAMPLESDIR})
.endfor
.endif

.include <bsd.port.mk>
