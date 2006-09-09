# ports collection makefile for:	hf
# Date created:		31 July 2006
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	hf
PORTVERSION=	0.7.3
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hfterm

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio soundcard fsk, pactor 1, amtor, gtor, mt63

RUN_DEPENDS=	whiptail:${PORTSDIR}/devel/newt

USE_GNOME=	gtk12
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX} --mandir=${PREFIX}/man

ONLY_FOR_ARCHS=	i386

MAN1=		dcf77gen.1 dcf77rx.1 hf.1 hfterm.1 hfkernel.1

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
	${WRKSRC}/util/Makefile ${WRKSRC}/test/Makefile \
	${WRKSRC}/hfkernel/Makefile ${WRKSRC}/dcf77/Makefile \
	${WRKSRC}/scripts/Makefile

post-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/hf-examplefiles
.for d in ${WRKSRC}/doc/hf-examplefiles/fix.01 \
	${WRKSRC}/doc/hf-examplefiles/fix.02 \
	${WRKSRC}/doc/hf-examplefiles/fix.03 \
	${WRKSRC}/doc/hf-examplefiles/fix.04 \
	${WRKSRC}/doc/hf-examplefiles/fix.05 \
	${WRKSRC}/doc/hf-examplefiles/fix.06 \
	${WRKSRC}/doc/hf-examplefiles/fix.07 \
	${WRKSRC}/doc/hf-examplefiles/fix.08 \
	${WRKSRC}/doc/hf-examplefiles/fix.09 \
	${WRKSRC}/doc/hf-examplefiles/fix.10 \
	${WRKSRC}/doc/hf-examplefiles/fix.11 \
	${WRKSRC}/doc/hf-examplefiles/fix.12 \
	${WRKSRC}/doc/hf-examplefiles/hfterm.brag \
	${WRKSRC}/doc/hf-examplefiles/gag \
	${WRKSRC}/doc/hf-examplefiles/littleman.ascii
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR}/hf-examplefiles
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/doc/AUTHORS ${WRKSRC}/doc/README \
	${WRKSRC}/doc/index.html ${WRKSRC}/doc/ChangeLog \
	${WRKSRC}/doc/chan_formulas.ps ${WRKSRC}/doc/lfconv.jpg \
	${WRKSRC}/doc/DE-HF-HOWTO.txt ${WRKSRC}/doc/chan_formulas.tex \
	${WRKSRC}/doc/mt63.txt ${WRKSRC}/doc/HF-HOWTO.txt \
	${WRKSRC}/doc/dcf77.txt ${WRKSRC}/doc/pactor.ps \
	${WRKSRC}/doc/INSTALL ${WRKSRC}/doc/english.txt \
	${WRKSRC}/doc/pactor.txt ${WRKSRC}/doc/LIESMICH \
	${WRKSRC}/doc/pactor_statediag.fig \
	${WRKSRC}/doc/P-MB-list.txt ${WRKSRC}/doc/hf.spec \
	${WRKSRC}/doc/su1.priv.txt
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "hf docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	doesn't build
.endif

.include <bsd.port.post.mk>
