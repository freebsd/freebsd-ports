// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_ENTERPRISE_SIGNALS_DEVICE_INFO_FETCHER_FREEBSD_H_
#define CHROME_BROWSER_ENTERPRISE_SIGNALS_DEVICE_INFO_FETCHER_FREEBSD_H_

#include "chrome/browser/enterprise/signals/device_info_fetcher.h"

namespace enterprise_signals {

// FreeBSD implementation of DeviceInfoFetcher.
class DeviceInfoFetcherFreeBSD : public DeviceInfoFetcher {
 public:
  DeviceInfoFetcherFreeBSD();
  DeviceInfoFetcherFreeBSD(const DeviceInfoFetcherFreeBSD&) = delete;
  DeviceInfoFetcherFreeBSD& operator=(const DeviceInfoFetcherFreeBSD&) = delete;
  ~DeviceInfoFetcherFreeBSD() override;

  // Overrides DeviceInfoFetcher:
  DeviceInfo Fetch() override;
};

}  // namespace enterprise_signals

#endif  // CHROME_BROWSER_ENTERPRISE_SIGNALS_DEVICE_INFO_FETCHER_FREEBSD_H_
