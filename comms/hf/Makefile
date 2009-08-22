# ports collection makefile for:	hf
# Date created:		31 July 2006
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	hf
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}term/${PORTNAME}/${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio soundcard fsk, pactor 1, amtor, gtor, mt63

RUN_DEPENDS=	whiptail:${PORTSDIR}/devel/newt

USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}

MANLANG=	"" "de.ISO8859-1"
MAN1=		hf.1 hfterm.1 hfkernel.1
MAN1_EN=	dcf77gen.1 dcf77rx.1
CONFLICTS=	sysutils/lbl-hf-1.*

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
	    ${WRKSRC}/hfkernel/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	    ${WRKSRC}/util/reffreq.c ${WRKSRC}/scripts/Makefile

post-install:
	@${ECHO} ""
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for d in ${WRKSRC}/doc/hf-examplefiles/fix.[0-1]*[0-9]* \
	${WRKSRC}/doc/hf-examplefiles/gag
	@${INSTALL_DATA} ${WRKSRC}/${d} ${EXAMPLESDIR}
.endfor
	@${ECHO} "hf examples installed in ${EXAMPLESDIR}"
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/doc/AUTHORS ${WRKSRC}/doc/ChangeLog \
	${WRKSRC}/doc/DE-HF-HOWTO.txt ${WRKSRC}/doc/HF-HOWTO.txt \
	${WRKSRC}/doc/INSTALL ${WRKSRC}/doc/LIESMICH \
	${WRKSRC}/doc/P-MB-list.txt ${WRKSRC}/doc/README \
	${WRKSRC}/doc/chan_formulas.ps ${WRKSRC}/doc/chan_formulas.tex \
	${WRKSRC}/doc/dcf77.txt  ${WRKSRC}/doc/english.txt \
	${WRKSRC}/doc/lfconv.jpg ${WRKSRC}/doc/mt63.txt \
	${WRKSRC}/doc/pactor.ps ${WRKSRC}/doc/pactor.txt \
	${WRKSRC}/doc/pactor_statediag.fig
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO} "hf docs installed in ${DOCSDIR}"
.endif
	@${ECHO} ""

.include <bsd.port.mk>
