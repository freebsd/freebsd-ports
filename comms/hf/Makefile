# ports collection makefile for:	hf
# Date created:		31 July 2006
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	hf
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hfterm

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio soundcard fsk, pactor 1, amtor, gtor, mt63

RUN_DEPENDS=	whiptail:${PORTSDIR}/devel/newt

USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}

ONLY_FOR_ARCHS=	i386

MANLANG=	"" "de.ISO8859-1"
MAN1=		hf.1 hfterm.1 hfkernel.1
MAN1_EN=	dcf77gen.1 dcf77rx.1

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
	${WRKSRC}/hfkernel/Makefile

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
	${WRKSRC}/doc/hf-examplefiles/gag
	${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR}/hf-examplefiles
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/doc/AUTHORS ${WRKSRC}/doc/ChangeLog \
	${WRKSRC}/doc/DE-HF-HOWTO.txt ${WRKSRC}/doc/HF-HOWTO.txt \
	${WRKSRC}/doc/INSTALL ${WRKSRC}/doc/LIESMICH \
	${WRKSRC}/doc/P-MB-list.txt ${WRKSRC}/doc/README \
	${WRKSRC}/doc/chan_formulas.ps ${WRKSRC}/doc/chan_formulas.tex \
	${WRKSRC}/doc/dcf77.txt  ${WRKSRC}/doc/english.txt \
	${WRKSRC}/doc/lfconv.jpg ${WRKSRC}/doc/mt63.txt \
	${WRKSRC}/doc/pactor.ps ${WRKSRC}/doc/pactor.txt \
	${WRKSRC}/doc/pactor_statediag.fig
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "hf docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
