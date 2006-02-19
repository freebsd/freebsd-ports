# New ports collection makefile for:	Mono and it's consumers
# Date created:				15 October 2005
# Whom:					Tom McLaughlin <tmclaugh@FreeBSD.org>
#
# bsd.mono.mk: accomodate the peculiarities of building C# ports within
# the FreeBSD ports system.
#
# $FreeBSD$
#   $Id: bsd.mono.mk,v 1.10 2006/02/16 00:37:15 tmclau02 Exp $
#

# Set the location of the .wapi directory so we write to a location we
# can always assume to be writable.
MONO_SHARED_DIR=${WRKDIR}
CONFIGURE_ENV+=MONO_SHARED_DIR="${MONO_SHARED_DIR}"
MAKE_ENV+=MONO_SHARED_DIR="${MONO_SHARED_DIR}"

# Set the location that webaps served bp XSP should use.
XSP_DOCROOT=${PREFIX}/www/xsp

# Clean up the semaphore produced by the .wapi
post-install: mono-semdel
pre-clean: mono-semdel

mono-semdel:
	@${SETENV} G_DEBUG="" MONO_SHARED_DIR="${MONO_SHARED_DIR}" ${LOCALBASE}/bin/mono-semdel 2> /dev/null || true
