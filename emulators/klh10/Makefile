# New ports collection makefile for:   klh10
# Date created:        11 January 2002
# Whom:                kstailey
#
# $FreeBSD$
#

PORTNAME=	klh10
PORTVERSION=	2.0a
CATEGORIES=	emulators
MASTER_SITES=	http://klh10.trailing-edge.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}.tgz klh10-2.0a-aux.tgz

MAINTAINER=	kstailey@yahoo.com
COMMENT=	Emulator for DEC PDP-10

ONLY_FOR_ARCHS=	i386

BUILD_WRKSRC=	${WRKSRC}/bld/fbx86
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# KSITS_ prefix for Komputer Small Incompatible Timesharing System
# a KLH10 configuration.

# KSITS_KLH10_HOME and KSITS_DRIVER_DIR must be set to the same
# locations that the its port uses.

KSITS_KLH10_DIR=	klh10-ks-its
KSITS_KLH10_HOME=	${PREFIX}/share/${KSITS_KLH10_DIR}
KSITS_DRIVER_DIR=	${PREFIX}/libexec/${KSITS_KLH10_DIR}
KSITS_DOCDIR=		${PREFIX}/share/doc/${KSITS_KLH10_DIR}
# someday add support for base-kl and base-ks targets
MAKE_ENV+=		KLH10_HOME=${KSITS_KLH10_HOME}
ALL_TARGET=		base-ks-its

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

pre-install:
	@ ${MKDIR} ${KSITS_KLH10_HOME}
	@ ${MKDIR} ${KSITS_DRIVER_DIR}
	@ ${MKDIR} ${KSITS_DOCDIR}

post-install:
.for file in ${KSITS_NATIVE_PROGS} ${KSITS_EM_DRIVERS} ${KSITS_EM_SDRIVERS}
	@ ${STRIP_CMD} ${KSITS_KLH10_HOME}/${file}
.endfor
.for file in ${KSITS_NATIVE_PROGS}
	@ ${MV} ${KSITS_KLH10_HOME}/${file} ${PREFIX}/bin
.endfor
.for file in ${KSITS_EM_DRIVERS} ${KSITS_EM_SDRIVERS}
	@ ${MV} ${KSITS_KLH10_HOME}/${file} ${KSITS_DRIVER_DIR}
.endfor
.for file in ${KSITS_EM_SDRIVERS}
	@ ${CHGRP} network ${KSITS_DRIVER_DIR}/${file}
	@ ${CHMOD} 4754 ${KSITS_DRIVER_DIR}/${file}
.endfor
.for file in ${KSITS_EM_DAT}
	@ ${INSTALL_DATA} ${WRKSRC}/run/ksits/${file} ${KSITS_KLH10_HOME}
.endfor
	@ ${INSTALL_MAN} ${WRKSRC}/run/ksits/README ${KSITS_DOCDIR}
	@ ${MKDIR} ${KSITS_DOCDIR}/pubits/adm
	@ ${MKDIR} ${KSITS_DOCDIR}/pubits/doc
.for file in ${KSITS_DOCS}
	@ ${INSTALL_MAN} ${WRKSRC}/doc/${file} ${KSITS_DOCDIR}
.endfor
.for file in ${KSITS_PUBADM}
	@ ${INSTALL_MAN} ${WRKSRC}/run/ksits/pubits/adm/${file} \
		${KSITS_DOCDIR}/pubits/adm
.endfor
.for file in ${KSITS_PUBDOC}
	@ ${INSTALL_MAN} ${WRKSRC}/run/ksits/pubits/doc/${file} \
		${KSITS_DOCDIR}/pubits/doc
.endfor
	@ ${INSTALL_MAN} ${FILESDIR}/PDPs ${KSITS_DOCDIR}
	@ ${ECHO} !!! KLH10 contains a setuid that accepts network connections.
	@ ${ECHO} !!! Consider using a firewall to limit access to KLH10.
	@ ${ECHO} !!! See the ${KSITS_DOCDIR}/pubits/adm
	@ ${ECHO} !!! for firewall documentation.

.include <bsd.port.mk>
