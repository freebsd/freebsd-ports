# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rexx-imc
PORTVERSION=	1.76
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.ox.ac.uk/people/ian.collier/distribution/ \
		ftp://ftp.sai.msu.su/pub/unix/rexx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Procedural programming language designed by IBM's UK Laboratories

CONFLICTS=	rexx-regina-* oorexx-[0-9]*

BROKEN_armv6=		fails to link: /nxb-bin/usr/bin/ld: hidden symbol __aeabi_uidivmod in libgcc.a is referenced by DSO
BROKEN_armv7=		fails to link: /nxb-bin/usr/bin/ld: hidden symbol __aeabi_uidivmod in libgcc.a is referenced by DSO

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Make
CONFIGURE_ENV=		PREFIX="${PREFIX}"
CONFIGURE_ARGS=		o all

# configures and builds in one step
NO_BUILD=		yes
USE_LDCONFIG=		yes

DOCFILES=	rexx.info rexx.ref rexx.summary rexx.tech
RMEFILES=	README README.Y2K README.bugreport README.docs \
		README.files README.make README.news README.platforms

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
# CFLAGS safeness for ARCHs other than i386
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Make
# CC safeness
	@${REINPLACE_CMD} -E -e 's|^CC=.+$$|CC=${CC}|' ${WRKSRC}/Make

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} rexx rxque rxstack \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/rexxsaa.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/librexx.so.2 ${WRKSRC}/rxmathfn.rxfn \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/rxmathfn.rxlib ${STAGEDIR}${PREFIX}/lib
	${LN} -sf librexx.so.2 ${STAGEDIR}${PREFIX}/lib/librexx.so
	(cd ${WRKSRC} && ${INSTALL_MAN} rexx.1 rxstack.1 rxque.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${RMEFILES} \
		${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} box rexxcps.rexx rexxtest.rexx \
		rxmathfn.rexx shell.rexx ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
