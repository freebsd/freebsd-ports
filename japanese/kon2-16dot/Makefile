# New ports collection makefile for:	kon2 with 16dot font
# Date created:         11 Apr 1997
# Whom:                 Makoto Matsushita <matusita@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kon2
PORTVERSION=	0.3
PORTREVISION=	6
# '+=' is for slave ports
CATEGORIES+=	japanese
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
PKGNAMESUFFIX=	-${KONFONT}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		k14.bdf 7x14rk.bdf \
		jiskan16.bdf 8x16rk.bdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# '+=' is for slave ports
MAINTAINER?=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Kanji On Console -- Display kanji characters on your own console

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		kon.1
MANLANG=	ja

PORTDOCS=	README README.FreeBSD
SUB_LIST=	KON16FONT=${KON16FONT} \
		KON14FONT=${KON14FONT}

.include <bsd.port.pre.mk>

.if !defined(KONFONT)
KONFONT=16dot
KON16FONT=Startup
.elif (${KONFONT} == "14dot")
KON14FONT=Startup
.elif (${KONFONT} != "16dot")
.BEGIN:
	@${ECHO} "Error: \$${KONFONT} (\"${KONFONT}\") should be either \"14dot\" or \"16dot\"."
	@${FALSE}
.endif

post-extract:
	cd ${WRKSRC} && \
		${INSTALL_MAN} doc/kon.1 src/kon.1.in && \
		${INSTALL_DATA} kon.cfg.FreeBSD kon.cfg.FreeBSD.in

${WRKSRC}/.config::
	(${ECHO_CMD} "DISTDIR = ${DISTDIR}"; \
	 ${ECHO_CMD} "TOPDIR = ${PREFIX}"; \
	 ${CAT} ${FILESDIR}/dotconfig; \
	) > ${WRKSRC}/.config

pre-configure: ${WRKSRC}/.config

do-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.FreeBSD config

post-configure:
	cd ${WRKSRC} &&	\
		for F in kon.cfg.FreeBSD src/kon.1; do \
			${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
			    < $${F}.in > $${F}; \
		done

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/kon.1 ${MANPREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
