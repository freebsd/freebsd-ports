# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	qico
PORTVERSION=	0.59.1
CATEGORIES=	comms

MAINTAINER=	admin@5034.ru
COMMENT=	FidoNet Technology Network (FTN) compatible mailer for Unix systems

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	kosfango
GH_PROJECT=	qico
GH_TAGNAME=	15673bf

GNU_CONFIGURE=	yes

CONFDIR?=	${PREFIX}/etc/fido/qico
QBASEDIR?=	/var/spool/fido/qico
QLOGDIR?=	/var/log/fido/qico
PLIST_SUB=	QBASEDIR=${QBASEDIR} QLOGDIR=${QLOGDIR}

.if defined(WITH_OPENLOCK)
CONFIGURE_ARGS+=	--with-lock-style=open
.endif
CONFIGURE_ARGS+=	--with-config=${CONFDIR}/qico.conf \
			--with-default-speed=115200
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		Changes FAQ README
EXAMPLES=	koi8r_866.cp onchat qhistory qico.xpm qlinks sfreq \
		stat.run synctime test.pl tossing

MANS=		qcc.8 qctl.8 qico.8
OPTIONS_DEFINE=	QCC PERL HYDRA
QCC_DESC=	Build Qico control center (qcc)
PERL_DESC=	Enable Perl-hooks support
HYDRA_DESC=	Enable Hydra 4K/8K/16K protocol extensions
OPTIONS_DEFAULT=	PERL QCC

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MQCC}
CONFIGURE_ARGS+=--disable-qcc
PLIST_SUB+=	QCC="@comment "
.else
PLIST_SUB+=	QCC=""
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=--enable-perl
USES+=		perl5
.endif

.if ${PORT_OPTIONS:MHYDRA}
CONFIGURE_ARGS+=--enable-hydra8k
.endif

do-install:
.for i in ${QLOGDIR} ${QBASEDIR}/fbox ${QBASEDIR}/inbound/unknown \
		${QBASEDIR}/outbound ${QBASEDIR}/qstoutb
	${MKDIR} ${STAGEDIR}${i}
.endfor
	${MKDIR} ${STAGEDIR}${CONFDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/qico ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/qctl ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MQCC}
	${INSTALL_PROGRAM} ${WRKSRC}/src/qcc ${STAGEDIR}${PREFIX}/bin/
.endif
	${INSTALL_DATA} ${WRKSRC}/qico.conf.sample ${STAGEDIR}${CONFDIR}/qico.conf.sample
	${INSTALL_DATA} ${WRKSRC}/qico.substs.sample ${STAGEDIR}${CONFDIR}/qico.substs.sample
	${INSTALL_DATA} ${WRKSRC}/qico.passwd.sample ${STAGEDIR}${CONFDIR}/qico.passwd.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}.ru
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/stuff/${i} ${STAGEDIR}${EXAMPLESDIR}/${i}
.endfor
.for i in ${MANS}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${STAGEDIR}${PREFIX}/man/man8/${i}
.endfor

.include <bsd.port.mk>
