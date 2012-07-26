# New ports collection makefile for:	qtel
# Date Created:		2012-05-22
# Whome:		Stephen Hurd <shurd@sasktel.net>
#
# $FreeBSD$
#

PORTNAME=	qtel
PORTVERSION=	11.05
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	svxlink/svxlink/${PORTVERSION}
DISTNAME=	svxlink-${PORTVERSION}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Qt EchoLink Client and SvrLink audio server

LIB_DEPENDS=	sigc-1.2:${PORTSDIR}/devel/libsigc++12 \
		speex:${PORTSDIR}/audio/speex \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gsm:${PORTSDIR}/audio/gsm \
		popt:${PORTSDIR}/devel/popt

MAN1=	svxlink.1 \
	remotetrx.1 \
	siglevdetcal.1 \
	qtel.1
MAN5=	svxlink.conf.5 \
	ModuleHelp.conf.5 \
	ModuleParrot.conf.5 \
	ModuleEchoLink.conf.5 \
	ModuleTclVoiceMail.conf.5 \
	ModuleDtmfRepeater.conf.5 \
	ModulePropagationMonitor.conf.5 \
	ModuleSelCallEnc.conf.5 \
	remotetrx.conf.5
MANCOMPRESSED=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
USE_TCL=	yes
USE_PKGCONFIG=	yes
USE_RC_SUBR=	svxlink remotetrx
USE_LDCONFIG=	${LOCALBASE}/lib ${LOCALBASE}/lib/svxlink

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 802517
BROKEN=		will not compile before Version 8.2 STABLE
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		`grep -lr %%LOCALBASE%% ${WRKSRC}`
	@${REINPLACE_CMD} -e 's|%%MAN1PREFIX%%|${MAN1PREFIX}|' \
		`grep -lr %%MAN1PREFIX%% ${WRKSRC}`
	@${REINPLACE_CMD} -e 's|%%MAN5PREFIX%%|${MAN5PREFIX}|' \
		`grep -lr %%MAN5PREFIX%% ${WRKSRC}`

.include <bsd.port.post.mk>
