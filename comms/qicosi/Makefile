# New ports collection makefile for:	qicosi
# Date created:				26 May 2004
# Whom:					Andrey Slusar <vasallia@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	qicosi
PORTVERSION=	0.57.1
CATEGORIES=	comms
MASTER_SITES=	http://193.232.248.13:8080/qicoxe/
DISTNAME=	qico-${PORTVERSION}xe

MAINTAINER=	anrays@gmail.com
COMMENT=	Ip/modem fido compatible mailer

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CONFDIR?=	${PREFIX}/etc/fido/qico

.if defined(WITH_OPENLOCK)
CONFIGURE_ARGS+=	--with-lock-style=open
.endif
CONFIGURE_ARGS+=	--with-config=${CONFDIR}/qico.conf \
			--with-default-speed=115200
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		Changes FAQ README
EXAMPLES=	koi8r_866.cp onchat qhistory qico.xpm qlinks sfreq \
		stat.run synctime test.pl tossing

MAN8=		qcc.8 qctl.8 qico.8

post-install:
	${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/qico.conf.sample ${CONFDIR}/qico.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}.ru
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/stuff/${i} ${EXAMPLESDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
