# Created by: kstailey
# $FreeBSD$

PORTNAME=	klh10
PORTVERSION=	2.0a
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://klh10.trailing-edge.com/
DISTFILES=	${DISTNAME}.tgz klh10-2.0a-aux.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for DEC PDP-10

ONLY_FOR_ARCHS=	i386

BUILD_WRKSRC=	${WRKSRC}/bld/fbx86
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# someday add support for base-kl and base-ks targets
MAKE_ENV=		KLH10_HOME="${DATADIR}"
ALL_TARGET=		base-ks-its

SUB_FILES=		pkg-message

DATADIR=		${PREFIX}/share/${KSITS_KLH10_DIR}
DOCSDIR=		${PREFIX}/share/doc/${KSITS_KLH10_DIR}

KSITS_KLH10_DIR=	klh10-ks-its
KSITS_DRIVER_DIR=	${PREFIX}/libexec/${KSITS_KLH10_DIR}

KSITS_NATIVE_PROGS=	kn10-ks \
			tapedd \
			udlconv \
			vdkfmt \
			wfconv \
			wxtest

KSITS_EM_DRIVERS=	dprpxx \
			dptm03

KSITS_EM_SDRIVERS=	dpimp

KSITS_EM_DAT=		@.ddt-u \
			@.its-647kn-u \
			@.nsalv-260-u \
			itsbin.647kn-u \
			klh10-kn.ini

KSITS_PUBADM=		hosts.its \
			its.ipfw \
			rc.firewall-its \
			router.notes

KSITS_PUBDOC=		bootload.files \
			distrib.its \
			dumpsys.help

KSITS_DOCS=		Intro.txt \
			backgrnd.txt \
			cmdref.txt \
			cmdsum.txt \
			coding.txt \
			dfkfb.txt \
			dvhost.txt \
			history.txt \
			install.txt \
			kldiff.txt \
			klt10.txt \
			klt20.txt \
			ksits.txt \
			kst10.txt \
			kst20.txt \
			news.txt \
			usage.txt \
			utils.txt \
			vtape.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|logf |log_f |g ; \
		 s|logf,|log_f,|g ; \
		 s|logf;|log_f;|g ; \
		 s|logf)|log_f)|g'

do-install:
.for i in ${KSITS_NATIVE_PROGS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${KSITS_DRIVER_DIR}
.for i in ${KSITS_EM_DRIVERS} ${KSITS_EM_SDRIVERS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${i} ${STAGEDIR}${KSITS_DRIVER_DIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in ${KSITS_EM_DAT}
	${INSTALL_DATA} ${WRKSRC}/run/ksits/${i} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/flushed

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/PDPs ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/run/ksits/README ${STAGEDIR}${DOCSDIR}
.for i in ${KSITS_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pubits/adm
.for i in ${KSITS_PUBADM}
	${INSTALL_DATA} ${WRKSRC}/run/ksits/pubits/adm/${i} ${STAGEDIR}${DOCSDIR}/pubits/adm
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pubits/doc
.for i in ${KSITS_PUBDOC}
	${INSTALL_DATA} ${WRKSRC}/run/ksits/pubits/doc/${i} ${STAGEDIR}${DOCSDIR}/pubits/doc
.endfor

.include <bsd.port.mk>
