# New ports collection makefile for:	ja-groff
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	groff
PORTVERSION=	0.99.1.1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTNAME=	${PORTNAME}-1.11.1

PATCH_SITES=	${MASTER_SITE_PORTS_JP} \
		http://www.tg.rim.or.jp/~inagaki/
PATCHFILES=	j${PORTNAME}-${PORTVERSION:R}.diff.gz \
		j${PORTNAME}-${PORTVERSION:R}-${PORTVERSION}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	okazaki@be.to

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	INSTALL="${INSTALL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" INSTALL_MAN="${INSTALL_MAN}"

DESCS=		${WRKSRC}/devnippon/DESC.proto ${WRKSRC}/devps/DESC.in

MAN1=		groff.1 gtroff.1 gtbl.1 gpic.1 geqn.1 grops.1 grotty.1 \
		grodvi.1 tfmtodit.1 grolj4.1 hpftodit.1 grefer.1 glookbib.1 \
		gindxbib.1 lkbib.1 gsoelim.1 addftinfo.1 pfbtops.1 psbb.1 \
		afmtodit.1 grog.1 gnroff.1
MAN5=		groff_font.5 groff_out.5
MAN7=		me.7 msafer.7 groff_char.7 groff_mm.7 groff_mmse.7 groff_ms.7
MANCOMPRESSED= yes

post-extract:
	@${RM} ${WRKSRC}/config.cache
	@${RM} ${WRKSRC}/config.log

#for not writing "/usr/local" explicitly in the patch
post-patch:
	@for f in ${DESCS}; do \
	  ${MV} -f $${f} $${f}.tmp; \
	  ${SED} -e '$$d' $${f}.tmp > $${f}; \
	  case $${f} in \
	    */devnippon/*) \
		${ECHO} "postpro ${PREFIX}/bin/grotty" >> $${f}; \
		;; \
	    */devps/*) \
		${ECHO} "postpro ${PREFIX}/bin/grops" >> $${f}; \
		;; \
	  esac; \
	done

.include <bsd.port.pre.mk>

post-install:
	@${CP} -p /usr/share/tmac/tmac.an ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.andoc ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.groff_an ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.orig_me ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/tmac.vgrind ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/eqnrc ${PREFIX}/share/groff/tmac
.if ${OSVERSION} >= 400000
	@${CP} -p /usr/share/tmac/locale/hyphen.us-ru ${PREFIX}/share/groff/tmac
.else
	@${CP} -p /usr/share/tmac/hyphen.us-ru ${PREFIX}/share/groff/tmac
.endif
	@${CP} -p /usr/share/tmac/troffrc ${PREFIX}/share/groff/tmac
	@${CP} -p /usr/share/tmac/mdoc/doc-common ${PREFIX}/share/groff/tmac/mdoc
	@${CP} -p /usr/share/tmac/mdoc/doc-syms ${PREFIX}/share/groff/tmac/mdoc
	@${PATCH} -d ${PREFIX}/share/groff/tmac < ${FILESDIR}/rc.diff

.include <bsd.port.post.mk>
