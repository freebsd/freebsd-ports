# Created by: db
# $FreeBSD$

PORTNAME=	hf
PORTVERSION=	0.8
PORTREVISION=	9
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}term/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio soundcard fsk, pactor 1, amtor, gtor, mt63

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	whiptail:devel/newt

USE_GNOME=	gtk12
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX} --sysconfdir=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFLICTS=	sysutils/lbl-hf-1.*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	    ${WRKSRC}/util/reffreq.c ${WRKSRC}/scripts/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for d in ${WRKSRC}/doc/hf-examplefiles/fix.[0-1]*[0-9]* \
	${WRKSRC}/doc/hf-examplefiles/gag
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${ECHO} "If examples are installed they will be found in ${EXAMPLESDIR}" >> ${WRKDIR}/pkg-message
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${WRKSRC}/doc/AUTHORS ${WRKSRC}/doc/ChangeLog \
	${WRKSRC}/doc/DE-HF-HOWTO.txt ${WRKSRC}/doc/HF-HOWTO.txt \
	${WRKSRC}/doc/INSTALL ${WRKSRC}/doc/LIESMICH \
	${WRKSRC}/doc/P-MB-list.txt ${WRKSRC}/doc/README \
	${WRKSRC}/doc/chan_formulas.ps ${WRKSRC}/doc/chan_formulas.tex \
	${WRKSRC}/doc/dcf77.txt  ${WRKSRC}/doc/english.txt \
	${WRKSRC}/doc/lfconv.jpg ${WRKSRC}/doc/mt63.txt \
	${WRKSRC}/doc/pactor.ps ${WRKSRC}/doc/pactor.txt \
	${WRKSRC}/doc/pactor_statediag.fig
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO} "If docs are installed they will be found in ${DOCSDIR}" >> ${WRKDIR}/pkg-message

.include <bsd.port.mk>
