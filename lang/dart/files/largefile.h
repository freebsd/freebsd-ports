// Copyright (c) 2026, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef RUNTIME_PLATFORM_LARGEFILE_H_
#define RUNTIME_PLATFORM_LARGEFILE_H_

#include "platform/globals.h"

// The Linux implementation uses the explicit large file interfaces (stat64,
// openat64, ...). On FreeBSD the regular interfaces are always 64-bit and
// there are no *64 variants, so map them to the regular names.
#if defined(__FreeBSD__)
#define fstat64 fstat
#define fstatat64 fstatat
#define ftruncate64 ftruncate
#define ino64_t ino_t
#define lseek64 lseek
#define lstat64 lstat
#define off64_t off_t
#define open64 open
#define openat64 openat
#define pread64 pread
#define stat64 stat
#endif  // defined(__FreeBSD__)

#endif  // RUNTIME_PLATFORM_LARGEFILE_H_
